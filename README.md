## 🛡️ Rapports et Audits de Cybersécurité / Système

Bienvenue sur ce dépôt. Il centralise mes différents comptes rendus techniques, rapports d'audit et documentations de déploiement réalisés dans le cadre de mes projets informatiques et de cybersécurité. 

Tous les livrables sont consultables directement au format PDF.

---

## 📂 Sommaire des documents

### 1. [Audit de sécurité physique et compromission locale](./Audit_de_securite_physique.pdf)
* **Sujet :** Test de la robustesse d'un mot de passe de session Windows classique face à une attaque physique.
* **Environnement et Outils :** Windows 10 Pro, image ISO / Live-CD Rescatux.
* **Résumé :** Démonstration pédagogique du contournement des protections logicielles via un accès physique. Le rapport détaille l'effacement du mot de passe administrateur dans la base SAM et met en évidence la nécessité d'une défense en profondeur (chiffrement BitLocker, verrouillage BIOS/UEFI).

### 2. [Déploiement et sécurisation d'un serveur NAS TrueNAS](./Menad_Yassine_truenas.pdf)
* [cite_start]**Sujet :** Installation, configuration et gestion des accès d'un serveur de stockage en réseau[cite: 109].
* **Environnement et Outils :** TrueNAS SCALE, Windows (Client), SMB, ACL.
* [cite_start]**Résumé :** Déploiement complet d'une infrastructure de stockage : création de pools et de datasets [cite: 206][cite_start], gestion fine des utilisateurs et des permissions via les listes de contrôle d'accès (ACL) [cite: 441][cite_start], et mise en place de partages SMB validés par des tests d'accès clients[cite: 618].

### 3. [Solution de sauvegarde et reprise sur sinistre avec Veeam](./veeam_yassine.pdf)
* **Sujet :** Déploiement d'une stratégie de sauvegarde centralisée et test de restauration complète.
* [cite_start]**Environnement et Outils :** Veeam Backup & Replication 12.3[cite: 975], Windows Server.
* [cite_start]**Résumé :** Mise en place de l'infrastructure de sauvegarde, incluant la configuration d'un dépôt local, le déploiement d'agents sur les postes clients et la planification des tâches[cite: 1182, 1186]. [cite_start]Le rapport documente également la création d'un support de récupération (ISO) et la validation d'une restauration Bare Metal[cite: 1389].

### 4. [Création d'un outil d'administration en script Bash](./Compte_rendu_script.pdf)
* [cite_start]**Sujet :** Développement d'un script Bash interactif pour l'automatisation de tâches d'administration système[cite: 70].
* **Environnement et Outils :** Linux, Bash.
* [cite_start]**Résumé :** Conception d'un utilitaire en ligne de commande intégrant un menu persistant [cite: 80] [cite_start]et une gestion optimisée des choix utilisateurs (structure `case`)[cite: 82]. [cite_start]Le compte rendu détaille la logique d'automatisation et les choix techniques visant à améliorer l'expérience utilisateur[cite: 83].

---
*Note : N'hésitez pas à consulter mon portfolio pour plus de détails sur mon parcours.*
